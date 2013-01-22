
//*************************************************************************************************************
//=============================================================================================================
// Includes
//=============================================================================================================

#include "commandmanager.h"


//*************************************************************************************************************
//=============================================================================================================
// Qt Includes
//=============================================================================================================

#include <QVector>
#include <QDebug>
#include <QJsonObject>


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace RTCOMMANDLIB;


//*************************************************************************************************************
//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

CommandManager::CommandManager(QByteArray &p_jsonDoc)
{
    m_jsonDocumentOrigin = QJsonDocument::fromJson(p_jsonDoc);

    insertJsonCommands(m_jsonDocumentOrigin);
}


//*************************************************************************************************************

void CommandManager::insertJsonCommands(QJsonDocument &p_jsonDocument)
{
    QJsonObject t_jsonObjectCommand;

    if(p_jsonDocument.isObject() && p_jsonDocument.object().value(QString("commands")) != QJsonValue::Undefined)
        t_jsonObjectCommand = p_jsonDocument.object().value(QString("commands")).toObject();
    else
        return;

    QJsonObject::Iterator it;
    for(it = t_jsonObjectCommand.begin(); it != t_jsonObjectCommand.end(); ++it)
        s_mapCommands.insert(it.key(), Command::fromQJsonObject(it.key(), it.value().toObject()));

}


//*************************************************************************************************************
//=============================================================================================================
// STATIC DEFINITIONS
//=============================================================================================================

QMap<QString, Command> CommandManager::s_mapCommands;
