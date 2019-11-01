/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <qmldesignercorelib_global.h>
#include <modelnode.h>
#include "qmlobjectnode.h"
#include "qmlstate.h"
#include "qmlvisualnode.h"

#include <QStringList>
#include <QRectF>
#include <QTransform>

namespace QmlDesigner {

class QmlModelStateGroup;
class QmlAnchors;
class ItemLibraryEntry;

class QMLDESIGNERCORE_EXPORT QmlItemNode : public QmlVisualNode
{
    friend class QmlAnchors;
public:
    QmlItemNode() : QmlVisualNode() {}
    QmlItemNode(const ModelNode &modelNode)  : QmlVisualNode(modelNode) {}
    bool isValid() const override;
    static bool isValidQmlItemNode(const ModelNode &modelNode);

    static bool isItemOrWindow(const ModelNode &modelNode);

    static QmlItemNode createQmlItemNode(AbstractView *view,
                                             const ItemLibraryEntry &itemLibraryEntry,
                                             const QPointF &position,
                                             QmlItemNode parentQmlItemNode);

    static QmlObjectNode createQmlObjectNode(AbstractView *view,
                                         const ItemLibraryEntry &itemLibraryEntry,
                                         const QPointF &position,
                                         QmlItemNode parentQmlItemNode);
    static QmlObjectNode createQmlObjectNode(AbstractView *view,
                                         const ItemLibraryEntry &itemLibraryEntry,
                                         const QPointF &position,
                                         NodeAbstractProperty parentproperty);
    static QmlItemNode createQmlItemNodeFromImage(AbstractView *view,
                                                  const QString &imageName,
                                                  const QPointF &position,
                                                  QmlItemNode parentQmlItemNode);
    static QmlItemNode createQmlItemNodeFromImage(AbstractView *view,
                                                  const QString &imageName,
                                                  const QPointF &position,
                                                  NodeAbstractProperty parentproperty);

    QList<QmlItemNode> children() const;
    QList<QmlObjectNode> resources() const;
    QList<QmlObjectNode> allDirectSubNodes() const;
    QmlAnchors anchors() const;

    bool hasChildren() const;
    bool hasResources() const;
    bool instanceHasAnchor(AnchorLineType sourceAnchorLineType) const;
    bool instanceHasAnchors() const;
    bool instanceHasShowContent() const;

    bool instanceCanReparent() const override;
    bool instanceIsAnchoredBySibling() const;
    bool instanceIsAnchoredByChildren() const;
    bool instanceIsMovable() const;
    bool instanceIsResizable() const;
    bool instanceIsInLayoutable() const;
    bool instanceHasRotationTransform() const;

    bool modelIsMovable() const;
    bool modelIsResizable() const;
    bool modelIsInLayout() const;

    QRectF instanceBoundingRect() const;
    QRectF instanceSceneBoundingRect() const;
    QRectF instancePaintedBoundingRect() const;
    QRectF instanceContentItemBoundingRect() const;
    QTransform instanceTransform() const;
    QTransform instanceTransformWithContentTransform() const;
    QTransform instanceTransformWithContentItemTransform() const;
    QTransform instanceSceneTransform() const;
    QTransform instanceSceneContentItemTransform() const;
    QPointF instanceScenePosition() const;
    QPointF instancePosition() const;
    QSizeF instanceSize() const;
    int instancePenWidth() const;
    bool instanceIsRenderPixmapNull() const;

    QPixmap instanceRenderPixmap() const;
    QPixmap instanceBlurredRenderPixmap() const;

    const QList<QmlItemNode> allDirectSubModelNodes() const;
    const QList<QmlItemNode> allSubModelNodes() const;
    bool hasAnySubModelNodes() const;

    void setPosition(const QPointF &position);
    void setPostionInBaseState(const QPointF &position);

    void setSize(const QSizeF &size);
    bool isInLayout() const;
    bool canBereparentedTo(const ModelNode &potentialParent) const;

    bool isInStackedContainer() const;
};

QMLDESIGNERCORE_EXPORT uint qHash(const QmlItemNode &node);

QMLDESIGNERCORE_EXPORT QList<ModelNode> toModelNodeList(const QList<QmlItemNode> &fxItemNodeList);
QMLDESIGNERCORE_EXPORT QList<QmlItemNode> toQmlItemNodeList(const QList<ModelNode> &modelNodeList);

} //QmlDesigner
