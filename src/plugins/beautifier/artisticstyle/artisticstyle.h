/****************************************************************************
**
** Copyright (C) 2016 Lorenz Haas
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

#include "../beautifierabstracttool.h"

#include "artisticstyleoptionspage.h"
#include "artisticstylesettings.h"

namespace Beautifier {
namespace Internal {
namespace ArtisticStyle {

class ArtisticStyle : public BeautifierAbstractTool
{
    Q_OBJECT

public:
    ArtisticStyle();

    QString id() const override;
    void updateActions(Core::IEditor *editor) override;
    TextEditor::Command command() const override;
    bool isApplicable(const Core::IDocument *document) const override;

private:
    void formatFile();
    QString configurationFile() const;
    TextEditor::Command command(const QString &cfgFile) const;

    QAction *m_formatFile = nullptr;
    ArtisticStyleSettings m_settings;
    ArtisticStyleOptionsPage m_page{&m_settings};
};

} // namespace ArtisticStyle
} // namespace Internal
} // namespace Beautifier
