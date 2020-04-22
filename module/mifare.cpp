#include "mifare.h"

Mifare::Mifare(Util *addr,QObject *parent) : QObject(parent)
{
    util=addr;
    isProcessingData=false;
    isProcessingKey=false;
}

void Mifare::processData(const QString str)
{
    if(isProcessingData)
    {
        if(inputType==FROM_RDBL)
        {

        }
    }
}
void Mifare::processKey(const QString str)
{
    if(isProcessingKey)
    {

    }
}
void Mifare::setProcessingState(ProcessingState st)
{
    if(st==Mifare::NONE)
    {
        isProcessingKey=false;
        isProcessingData=false;
    }
    else if(st==Mifare::KEY)
    {
        isProcessingKey=true;
        isProcessingData=false;
    }
    else if(st==Mifare::DATA)
    {
        isProcessingKey=false;
        isProcessingData=true;
    }
}
void Mifare::setInputType(InputType tp)
{
    inputType=tp;
}
