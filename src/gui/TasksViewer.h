#pragma once

#include <QWidget>

#include "ui_TasksViewer.h"

#include "TaskWidget.h"
#include "TaskData.h"

namespace month_flow
{
	class TasksViewer : public QWidget
	{
		Q_OBJECT

	public:
		explicit TasksViewer(QWidget* parent = nullptr);
		~TasksViewer() override;

		void CreateTask(const TaskData& taskData);

	signals:
		void CreateTaskClicked();

	public slots:
		void OnButtonRemoveClick();

	private slots:
		void OnButtonAddClicked();

	private:
		Ui::TasksViewer m_ui;

		std::vector<TaskWidget*> m_taskWidgets;
	};
}
