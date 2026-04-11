#pragma once

#include <QWidget>

#include "ui_CentralWidget.h"

#include "TaskWidget.h"

namespace month_flow
{
	class CentralWidget : public QWidget
	{
	public:
		explicit CentralWidget(QWidget* parent = nullptr);
		~CentralWidget() override;

	public slots:
		void OnButtonAddClicked();
		void OnButtonRemoveClick();

	private:
		Ui::CentralWidget m_ui;

		std::vector<TaskWidget*> m_taskWidgets;
	};
}
