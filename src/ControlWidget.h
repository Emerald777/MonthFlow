#pragma once

#include <QWidget>

#include "ui_ControlWidget.h"

#include "TaskWidget.h"

namespace month_flow
{
	class ControlWidget : public QWidget
	{
		Q_OBJECT

	public:
		explicit ControlWidget(QWidget* parent = nullptr);
		~ControlWidget() override;

		void CreateTask();

	signals:
		void CreateTaskClicked();

	public slots:
		void OnButtonRemoveClick();

	private slots:
		void OnButtonAddClicked();

	private:
		Ui::ControlWidget m_ui;

		std::vector<TaskWidget*> m_taskWidgets;
	};
}
