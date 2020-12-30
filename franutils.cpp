#include "franutils.h"

namespace franticUtils
{
    std::string qstToStd(QString qstToConv)
    {
    #if defined(Q_OS_WIN)
        return qstToConv.toLocal8Bit().constData();
    #else
        return qstToConv.toUtf8().constData();
    #endif
    }
}
