#pragma once

namespace month_flow
{
	enum class StackedPage
	{
		TasksView = 0,
		NewTaskDialog
	};

	inline int ToInt(StackedPage page) { return static_cast<int>(page); }
}
