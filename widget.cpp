#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <list>
#include <QFileInfo>
#include <QDir>
#include "hasheval.h"
#include <cstdio>
#include <QMessageBox>
#include <QFileDialog>
#include <QHeaderView>
#include <QClipboard>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
	m_model(new TableModel(this))
{
    ui->setupUi(this);
	ui->tableView->setModel(m_model);
	QHeaderView *l_hh = ui->tableView->horizontalHeader();
	l_hh->setResizeMode(0, QHeaderView::Stretch);
}


Widget::Widget(char *path, QWidget *parent) :
    QWidget(parent),
	source_path(path),
    ui(new Ui::Widget),
	m_model(new TableModel(this))
{
    ui->setupUi(this);
	ui->tableView->setModel(m_model);
	QHeaderView *l_hh = ui->tableView->horizontalHeader();
	l_hh->setResizeMode(0, QHeaderView::Stretch);
	on_pushButton_doIt_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_folderPath_clicked()
{
	const QString l_dir(QFileDialog::getExistingDirectory(this, windowTitle() + " - change folder",
		QFileInfo(ui->lineEdit_folderPath->text()).absoluteFilePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
	if (!l_dir.isEmpty())
		ui->lineEdit_folderPath->setText(l_dir);
}

void Widget::on_pushButton_doIt_clicked()
{
	int l_files = 0, l_dirs = 0;
	std::list<QString> l_list;
	if (!source_path.isEmpty())
	{
		l_list.push_back(source_path);
	}
	else
	{
		l_list.push_back(QFileInfo(ui->lineEdit_folderPath->text()).absoluteFilePath());
		if (QMessageBox::question(this, windowTitle() + " - question", QString("Continue with '%1'?").arg(l_list.front()), QMessageBox::Ok, QMessageBox::Cancel) != QMessageBox::Ok)
			return;
	}
	while (!l_list.empty())
	{
		const QString l_one(l_list.front());
		l_list.pop_front();
		QFileInfo l_fi(l_one);

		const QString l_cs(l_fi.completeSuffix());
		if (l_fi.baseName().size() > 8 || l_cs.size() > 3 || l_cs.contains("."))
		{
			const QString l_fn(l_fi.fileName());
			char q[1024];
			::sprintf_s(q, _countof(q), "%08X", hash(l_fn.toLocal8Bit()));
			const QString l_new(l_fi.isDir()? q: QString("%1.TXT").arg(q));
			QDir l_parent(l_fi.dir());
#ifdef _DEBUG
			if (!l_parent.path().startsWith("c:/teplomon/wc44", Qt::CaseInsensitive))
			{
				::terminate();
			}
#endif
			if (!l_parent.rename(l_fn, l_new))
			{
				QMessageBox::critical(this, windowTitle() + " - error", QString("Can't rename %1 - stop").arg(l_one));
				break;
			}
			std::vector<QString> l_s;
			l_s.push_back(l_one);
			l_s.push_back(l_new);
			m_model->insert(l_s);
			l_fi = QFileInfo(l_parent, l_new);
			if (l_fi.isFile())
				l_files++;
			if (l_fi.isDir())
				l_dirs++;
		}

		if (l_fi.isDir())
		{
			QDir l_dir(l_fi.absoluteFilePath());
			const QFileInfoList l_cont(l_dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot));
			for (int i = 0; i < l_cont.size(); i++)
				l_list.push_back(l_cont[i].absoluteFilePath());
		}
	}
	
	if (source_path.isEmpty())
	{
		QMessageBox::information(this, windowTitle() + " - info", QString("%1 file(s) and %2 folder(s) renamed").arg(l_files).arg(l_dirs));
	}
}

void Widget::on_pushButton_copy_clicked()
{
	auto l = m_model->data();
	QString l_t;
	for (size_t i = 0; i < l.size(); i++)
	{
		for (size_t j = 0; j < l[i].size(); j++)
			l_t += (j == 0? "": "\t") + l[i][j];
		l_t += "\n";
	}
	QClipboard *const l_clipboard = QApplication::clipboard();
	l_clipboard->setText(l_t);
}
