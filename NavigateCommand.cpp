/*  This file is part of SCView, a STEP-Express viewer
    Copyright (C) 2012 Laurent Bauer lahoraent@hotmail.com

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; version 2
    of the License.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "NavigateCommand.h"
#include "MainWindow.h"
#include <ExpDict.h>

#include <iostream>
using namespace std;

NavigateCommand::NavigateCommand(MainWindow *controler, const TypeDescriptor *oldDescriptor,  const TypeDescriptor *newDescriptor, QUndoCommand *parent)
    : QUndoCommand(parent)
    , m_Controler(controler)
    , m_OldDescriptor(oldDescriptor)
    , m_NewDescriptor(newDescriptor)
{
}

void NavigateCommand::undo()
{
    m_Controler->setDescriptor(m_OldDescriptor);
}

void NavigateCommand::redo()
{
    m_Controler->setDescriptor(m_NewDescriptor);
}





