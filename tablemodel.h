#ifndef __TABLEMODEL_H
#define __TABLEMODEL_H

#include <QAbstractTableModel>
#include <vector>

class TableModel: public QAbstractTableModel
{
    Q_OBJECT

public:
	TableModel(QObject *a);

	void insert(const std::vector<QString> &a);
	std::vector<std::vector<QString>> data() const;

private:
	virtual QVariant data(const QModelIndex &a_index, int a_role) const;
	virtual Qt::ItemFlags flags(const QModelIndex &a_index) const;
	virtual QVariant headerData(int a_section, Qt::Orientation a_orientation, int a_role = Qt::DisplayRole) const;
	virtual QModelIndex index(int a_row, int a_column, const QModelIndex &a_parent = QModelIndex()) const;
	virtual QModelIndex parent(const QModelIndex &a_index) const;
	virtual int rowCount(const QModelIndex &a_parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex &a_parent = QModelIndex()) const;

	std::vector<std::vector<QString>> m_data;
};

#endif //__TABLEMODEL_H
