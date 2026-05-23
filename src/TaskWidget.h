#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>

#include "ExpanderWidget.h"
#include "DeadlineStatus.h"

namespace month_flow
{
	class TaskWidget: public QWidget
	{
		Q_OBJECT

	public:
		explicit TaskWidget(const QString& name, QWidget* parent = nullptr);
		~TaskWidget() override;

		void SetCommentExpanded(bool isExpanded);
		void SetDeadlineStatus(DeadlineStatus newStatus);

	signals:
		void ButtonRemoveClick();

	protected:
		bool eventFilter(QObject* watched, QEvent* event) override;

	private:
		void CreateUi();
		QHBoxLayout* CreateBaseLineLayout();
		QHBoxLayout* CreateCommentLineLayout();

		ExpanderWidget* m_expander = nullptr;

		QLabel* m_labelName = nullptr;
		QLabel* m_labelDeadlineDay = nullptr;

		QFrame* m_commentPanel = nullptr;
		QLabel* m_labelComment = nullptr;

		QPushButton* m_buttonRemove = nullptr;
	};
}
