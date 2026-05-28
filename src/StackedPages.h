#pragma once

namespace month_flow
{
	enum class StackedPage
	{
		ProfileDialog = 0,
		TasksView,
		NewTaskDialog
	};

	inline int ToInt(StackedPage page) { return static_cast<int>(page); }
}
