#pragma once

#include <QWidget>

#include "ui_NewTaskDialog.h"

namespace month_flow
{
	class NewTaskDialog: public QWidget
	{
		Q_OBJECT

	public:
		explicit NewTaskDialog(QWidget* parent = nullptr);
		~NewTaskDialog() override;

	private:
		Ui::NewTaskDialog m_ui;
	};
}
