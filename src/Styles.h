#pragma once

namespace str
{
	inline const auto MainTaskWidgetStyle = R"(
		QLabel#expander {
			border-radius: 3px;
			border: 1px solid #c0c0c3;
			background-color: #c3c3c8;
			padding: 3px;
			min-width: 18px;
			max-width: 18px;
			min-height: 18px;
		}

		QLabel#deadline {
			border: 2px solid #6868d6;
			background-color: #a6a6e9;
			border-radius: 5px;
			font-size: 14px;
			min-width: 18px;
			min-height: 18px;
		}

		QLabel#left {
			border: 2px solid #686868;
			background-color: #a6a6a9;
			border-radius: 5px;
			font-size: 14px;
			min-width: 18px;
			min-height: 18px;
		}

		QLabel[status=far]#left {
			border: 2px solid #48e14b;
			background-color: #76ec79;
		}

		QLabel[status=approaching]#left {
			border: 2px solid #e4686b;
			background-color: #ec8689;
		}

		QLabel#task {
			border-radius: 3px;
			border: 1px solid #c0c0c3;
			background-color: #c3c3c8;
			color: #2c3e50;
			font-size: 14px;
			font-weight: bold;
			padding: 3px;
		}

		QLabel#comment {
			border-radius: 3px;
			border: 1px solid #a0a0a3;
			background-color: #a3a3a8;
			color: #2c3e50;
			font-size: 14px;
			font-weight: bold;
			padding: 3px;
		}
	)";
}
