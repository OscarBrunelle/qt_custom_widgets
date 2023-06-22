#include "customsearchwidget.h"
#include "common.h"

CustomSearchWidget::CustomSearchWidget(QString _table_name, QString _label_text, QString _column, QFormLayout *parent, int row)
{
	ui.setupUi(this);
	table_name = _table_name;
	column = _column;
	ui.searchLabel->setText(_label_text);
	update_list("", ui.resultsListWidget, table_name, column, results_index_list);
    if (parent != NULL) {
        if (row == -1) {
            parent->addRow(_label_text, ui.searchLineEdit);
            parent->addRow("", ui.resultsListWidget);
        } else {
            parent->insertRow(row, _label_text, ui.searchLineEdit);
            parent->insertRow(row, "", ui.resultsListWidget);
        }
    }
}

CustomSearchWidget::~CustomSearchWidget()
{
}

void CustomSearchWidget::on_searchLineEdit_textChanged(const QString &arg1)
{
	update_list(arg1, ui.resultsListWidget, table_name, column, results_index_list);
}

QString CustomSearchWidget::get_selected_id() {
	QModelIndexList selected_indexes = ui.resultsListWidget->selectionModel()->selectedIndexes();
	return ((selected_indexes.size() > 0) ? results_index_list.at(selected_indexes.at(0).row()) : NULL);
}
