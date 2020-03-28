/*
 * =====================================================================================
 *
 *       Filename: controlboard.hpp
 *        Created: 08/21/2016 04:12:57
 *    Description: main control pannel for running client
 *                 try support dynamically allocated control board
 *
 *        Version: 1.0
 *       Revision: none
 *       Compiler: gcc
 *
 *         Author: ANHONG
 *          Email: anhonghe@gmail.com
 *   Organization: USTC
 *
 * =====================================================================================
 */

#pragma once
#include <cstdint>
#include <functional>

#include "log.hpp"
#include "widget.hpp"
#include "pngtexdb.hpp"
#include "sdldevice.hpp"
#include "inputline.hpp"
#include "tritexbutton.hpp"
#include "linebrowserboard.hpp"

class ProcessRun;
class controlBoard: public Widget
{
    private:
        ProcessRun *m_ProcessRun;

    private:
        bool m_expand = false;

    private:
        TritexButton m_ButtonClose;
        TritexButton m_ButtonMinize;
        TritexButton m_ButtonInventory;

    private:
        InputLine        m_CmdLine;
        labelBoard       m_LocBoard;
        LineBrowserBoard m_LogBoard;

    public:
        controlBoard(
                int,            // x
                int,            // y
                int,            // screen width
                ProcessRun *,   // 
                Widget *,       //
                bool);          //

    public:
        ~controlBoard() = default;

    public:
        void drawEx(int, int, int, int, int, int);

    private:
        std::tuple<int, int> scheduleStretch() const;

    private:
        void drawLeft();
        void drawRight();
        void drawMiddleDefalt();
        void drawMiddleExpand();

    public:
        void Update(double);
        bool processEvent(const SDL_Event &, bool *);

    public:
        void InputLineDone();

    public:
        void AddLog(int, const char *);

    public:
        bool CheckMyHeroMoved();
};
