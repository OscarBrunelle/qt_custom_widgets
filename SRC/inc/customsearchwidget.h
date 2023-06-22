#ifndef CUSTOMSEARCHWIDGET_H
#define CUSTOMSEARCHWIDGET_H

#include <QWidget>
#include "ui_customsearchwidget.h"

class CustomSearchWidget : public QWidget
{
	Q_OBJECT

public:
    explicit CustomSearchWidget(QString _table_name = "", QString _label_text = "Recherche", QString _column = "", QFormLayout *parent = NULL, int row = -1);
	~CustomSearchWidget();
	QString get_selected_id();

private slots:
	void on_searchLineEdit_textChanged(const QString &arg1);

private:
	Ui::CustomSearchWidget ui;
	QString table_name;
	QString column;
	QList<QString> results_index_list = {};
};

#endif // CUSTOMSEARCHWIDGET_H
