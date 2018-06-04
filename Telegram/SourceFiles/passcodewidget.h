/*
This file is part of Telegram Desktop,
the official desktop version of Telegram messaging app, see https://telegram.org

Telegram Desktop is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

It is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

In addition, as a special exception, the copyright holders give permission
to link the code of portions of this program with the OpenSSL library.

Full license: https://github.com/telegramdesktop/tdesktop/blob/master/LICENSE
Copyright (c) 2014-2017 John Preston, https://desktop.telegram.org
*/
#pragma once

#include <QWidget>
#include <QResizeEvent>
#include <QPaintEvent>
#include "base/object_ptr.h"
#include "ui/animation.h"
#include "ui/twidget.h"

namespace Ui {
class PasswordInput;
class LinkButton;
class RoundButton;
} // namespace Ui

class PasscodeWidget : public TWidget {
	Q_OBJECT

public:
	PasscodeWidget(QWidget *parent);

	void setInnerFocus();

	void showAnimated(const QPixmap &bgAnimCache, bool back = false);

protected:
	void paintEvent(QPaintEvent *e) override;
	void resizeEvent(QResizeEvent *e) override;

public slots:
	void onError();
	void onChanged();
	void onSubmit();

private:
	void animationCallback();

	void showAll();
	void hideAll();

	Animation _a_show;
	bool _showBack = false;
	QPixmap _cacheUnder, _cacheOver;

	object_ptr<Ui::PasswordInput> _passcode;
	object_ptr<Ui::RoundButton> _submit;
	object_ptr<Ui::LinkButton> _logout;
	QString _error;

};
