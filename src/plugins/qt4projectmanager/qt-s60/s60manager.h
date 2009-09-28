/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact:  Qt Software Information (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
**************************************************************************/

#ifndef S60MANAGER_H
#define S60MANAGER_H

#include "qtversionmanager.h"
#include "serialdevicelister.h"
#include "s60devices.h"

#include <extensionsystem/iplugin.h>
#include <projectexplorer/toolchain.h>

#include <QtCore/QObject>

namespace Qt4ProjectManager {
namespace Internal {

class S60Manager : public QObject
{
    Q_OBJECT
public:
    S60Manager(QObject *parent = 0);
    ~S60Manager();
    static S60Manager *instance();

    ProjectExplorer::ToolChain *createWINSCWToolChain(const Qt4ProjectManager::QtVersion *version) const;
    ProjectExplorer::ToolChain *createGCCEToolChain(const Qt4ProjectManager::QtVersion *version) const;
    ProjectExplorer::ToolChain *createRVCTToolChain(const Qt4ProjectManager::QtVersion *version,
                                                    ProjectExplorer::ToolChain::ToolChainType type) const;

    S60Devices *devices() const { return m_devices; }
    S60Devices::Device deviceForQtVersion(const Qt4ProjectManager::QtVersion *version) const;
    QString deviceIdFromDetectionSource(const QString &autoDetectionSource) const;

    SerialDeviceLister *serialDeviceLister() const { return m_serialDeviceLister; }

private slots:
    void updateQtVersions();

private:
    void addAutoReleasedObject(QObject *p);

    static S60Manager *m_instance;

    S60Devices *m_devices;
    QObjectList m_pluginObjects;
    SerialDeviceLister *m_serialDeviceLister;
};

} // namespace Internal
} // namespace Qt4ProjectManager

#endif // S60MANAGER_H
