/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-FileCopyrightText: 2006-2010 RobotCub Consortium
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef PARTITEMTREE_H
#define PARTITEMTREE_H

#include <QWidget>
#include <unordered_map>


#include "jointItemTree.h"
#include "flowlayout.h"

class PartItemTree : public QWidget
{
    Q_OBJECT
    FlowLayout *m_layout;
    int m_index;
    QSize m_desiredElementSize;

public:
    explicit PartItemTree(int index, QWidget *parent = nullptr);

    int numberOfJoints() const;

    JointItemTree* addJoint();

    JointItemTree* getJoint(int index);

    void uniformLayout();

    void resizeEvent(QResizeEvent *event) override;

    QSize getMaxElementSize();

    void setDesiredElementSize(const QSize &maxSize);

signals:

    void sig_jointClicked(int partIndex, int jointIndex);

    void sig_homeClicked(int partIndex, int jointIndex);

    void sig_runClicked(int partIndex, int jointIndex);

    void sig_idleClicked(int partIndex, int jointIndex);

    void sig_PIDClicked(int partIndex, int jointIndex);

public slots:

    void onJointClicked(int index);

    void onHomeClicked(int index);

    void onRunClicked(int index);

    void onIdleClicked(int index);

    void onPIDClicked(int index);

};

#endif // PARTITEMTREE_H
