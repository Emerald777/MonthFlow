#pragma once

#include <QMainWindow>
#include "StackedPages.h"

class QStackedWidget;

namespace month_flow
{
	class ControlWidget;
	class NewTaskDialog;

	class MainWindow: public QMainWindow
	{
	public:
		MainWindow(QWidget* parent = nullptr);

	private:
		void CreateUi();
		void CreateConnections();
		void SelectPage(StackedPage page);

		QStackedWidget* m_stackWidget = nullptr;
		ControlWidget* m_controlWidget = nullptr;
		NewTaskDialog* m_newTaskDialog = nullptr;

	};
}
