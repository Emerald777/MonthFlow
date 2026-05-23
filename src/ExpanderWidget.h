#pragma once

#include <QLabel>

namespace month_flow
{
	class ExpanderWidget: public QLabel
	{
		Q_OBJECT

	public:
		explicit ExpanderWidget(QWidget* parent = nullptr);

		void SetExpanded(bool isExpanded);
	};
}
