#pragma once

#include <QMainWindow>

#include "StackedPages.h"
#include "TaskData.h"

class QStackedWidget;

namespace month_flow
{
	class TasksViewer;
	class NewTaskDialog;
	class ProfileDialog;

	class MainWindow: public QMainWindow
	{
	public:
		MainWindow(QWidget* parent = nullptr);

	public slots:
		void OnTaskCreated(const month_flow::TaskData& taskData);

	private:
		void CreateUi();
		void CreateConnections();
		void SelectPage(StackedPage page);

		QStackedWidget* m_stackWidget = nullptr;
		ProfileDialog* m_profileDialog = nullptr;
		TasksViewer* m_tasksViewer = nullptr;
		NewTaskDialog* m_newTaskDialog = nullptr;

	};
}
