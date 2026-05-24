#pragma once

#include <QWidget>

#include "ui_ControlWidget.h"

#include "TaskWidget.h"

namespace month_flow
{
	class ControlWidget : public QWidget
	{
	public:
		explicit ControlWidget(QWidget* parent = nullptr);
		~ControlWidget() override;

	public slots:
		void OnButtonAddClicked();
		void OnButtonRemoveClick();

	private:
		Ui::ControlWidget m_ui;

		std::vector<TaskWidget*> m_taskWidgets;
	};
}
