#include "tablemodel.h"

TableModel::TableModel(QObject *a)
	:QAbstractTableModel(a)
{}

void TableModel::insert(const std::vector<QString> &a)
{
	beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
	m_data.push_back(a);
	endInsertRows();
}

QVariant TableModel::data(const QModelIndex &a_index, int a_role) const
{
     if (!a_index.isValid() || a_role != Qt::DisplayRole)
		 return QVariant();
     return m_data[a_index.row()][a_index.column()];
}

Qt::ItemFlags TableModel::flags(const QModelIndex &a_index) const
{
	if (a_index.isValid())
		return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	return Qt::ItemFlags();
}

QVariant TableModel::headerData(int /*a_section*/, Qt::Orientation /*a_orientation*/, int /*a_role*/) const
{
	return QVariant();
}

QModelIndex TableModel::index(int a_row, int a_column, const QModelIndex &a_parent) const
{
	if (a_parent.isValid())
		return QModelIndex();
	return createIndex(a_row, a_column, 0);
}

QModelIndex TableModel::parent(const QModelIndex &/*a_index*/) const
{
	return QModelIndex();
}

int TableModel::rowCount(const QModelIndex &a_parent) const
{
	if (a_parent.isValid())
		return 0;
	return m_data.size();
}

int TableModel::columnCount(const QModelIndex &a_parent) const
{
	if (a_parent.isValid())
		return 0;
	return 2;
}

std::vector<std::vector<QString>> TableModel::data() const
{
	return m_data;
}
