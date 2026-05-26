#include "ExpanderWidget.h"

month_flow::ExpanderWidget::ExpanderWidget(QWidget* parent): QLabel(parent)
{
	setObjectName("expander");
	setScaledContents(true);
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

	SetExpanded(false);
}

void month_flow::ExpanderWidget::SetExpanded(bool isExpanded)
{
	setPixmap( isExpanded
		? QPixmap(":/images/opener_expanded.png")
		: QPixmap(":/images/opener_collapsed.png")
	);
}
