/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-FileCopyrightText: 2006-2010 RobotCub Consortium
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "sliderWithTarget.h"
#include <QKeyEvent>
#include <QPainter>
#include <QStyle>
#include <cmath>

//just because old VS2010 does not implement round() function in cmath
double my_round(double number)
{
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}

SliderWithTarget::SliderWithTarget(QWidget * parent) : QSlider(Qt::Horizontal, nullptr)
{
    sliderCurrentLabel = new QLabel(this);
    sliderCurrentLabel->setObjectName(QStringLiteral("sliderLabel"));
    sliderCurrentLabel->setGeometry(QRect(0, 0, 100, 20));
    sliderCurrentLabel->setMinimumSize(QSize(40, 20));
    sliderCurrentLabel->setMaximumSize(QSize(16777215, 20));
    sliderCurrentLabel->setAlignment(Qt::AlignCenter);
    sliderCurrentLabel->setStyleSheet("background-color: rgba(0,0,0,0%)");

    sliderTargetLabel = new QLabel(this);
    sliderTargetLabel->setObjectName(QStringLiteral("sliderTargetLabel"));
    sliderTargetLabel->setGeometry(QRect(0, 0, 100, 20));
    sliderTargetLabel->setMinimumSize(QSize(40, 20));
    sliderTargetLabel->setMaximumSize(QSize(16777215, 20));
    sliderTargetLabel->setAlignment(Qt::AlignCenter);
    sliderTargetLabel->setStyleSheet("background-color: rgba(0,0,0,0%)");

    disableClickOutOfHandle = true;
    target=-1e50; //default value is intensionally set out of the slider
    width_at_target = this->width() - 30;
    isDouble = false;
}

void SliderWithTarget::setSliderStep(double step)
{
    sliderStep = step;
}

double SliderWithTarget::getSliderStep()
{
    return sliderStep;
}

void SliderWithTarget::setIsDouble(bool b)
{
    isDouble = b;
}

bool SliderWithTarget::getIsDouble()
{
    return isDouble;
}

void SliderWithTarget::setValue(double val)
{
    if (isDouble)
    {
        //QSlider::setValue(round(val*sliderStep));
        QSlider::setValue(my_round(val*sliderStep));
    }
    else
    {
        QSlider::setValue(val);
    }
}

void SliderWithTarget::updateSliderTarget(double t)
{
    target = t;
    width_at_target= this->width()-30;
    this->update(); //force the repaint of the widget
}

void SliderWithTarget::resetTarget()
{
    target = -1e50;
    width_at_target = this->width() - 30;
    this->update(); //force the repaint of the widget
}

void SliderWithTarget::paintEvent(QPaintEvent *e)
{
    QSlider::paintEvent(e);
    double w = this->width() - 30;
    int totValues = this->maximum() + abs(this->minimum());

    if (enableViewTargetBox)
    {
        QPainter p(this);
        double newX = ((double)w / (double)totValues) * (target*sliderStep + abs(this->minimum()));
        QRect r(newX, 17, 30, 15);
        p.fillRect(r, QBrush(QColor(128, 128, 255, 128)));
        p.drawRect(r);
    }
    if (enableViewLabel)
    {
        double value = this->value();
        double newX = ((double)w / (double)totValues) * ((double)value + abs(this->minimum()));
        QString label_text = QString("%L1").arg((double)value / sliderStep, 0, 'f', number_of_decimals);
        sliderCurrentLabel->setText(label_text);
        sliderCurrentLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        //these adjustment are required to have the label properly aligned and
        //to avoid overflow
        if (newX<0) newX = 0;
        if (newX>w-30) newX = w-30;
        sliderCurrentLabel->setGeometry(newX, -10, 60, 20);
    }
    if (enableViewTargetValue)
    {
        double newX = ((double)w / (double)totValues) * ((double)target + abs(this->minimum()));
        QString label_text = QString("Ref:%L1").arg((double)target, 0, 'f', number_of_decimals);
        sliderTargetLabel->setText(label_text);
        sliderTargetLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        //these adjustment are required to have the label properly aligned and
        //to avoid overflow
        if (newX < 0) newX = 0;
        if (newX > w - 30) newX = w - 30;
        sliderTargetLabel->setGeometry(newX, +10, 60, 20);
    }
    else
    {
        sliderTargetLabel->setText("");
    }
}

void SliderWithTarget::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        double myx = event->x();
        QStyleOptionSlider opt;
        initStyleOption(&opt);
        QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

        //throw aways clicks that are not on the handle
        if (disableClickOutOfHandle)
        {
            if (myx<sr.left()+3 || myx>sr.right()-3)
            {
                return;
            }
        }

        //setValue(minimum() + ((maximum() - minimum()) * myx) / width());
        event->accept();
    }
    QSlider::mousePressEvent(event);
}

SliderWithTarget::~SliderWithTarget()
{
    if (sliderCurrentLabel) { delete sliderCurrentLabel; sliderCurrentLabel = nullptr; }
    if (sliderTargetLabel)  { delete sliderTargetLabel; sliderTargetLabel = nullptr; }
}
