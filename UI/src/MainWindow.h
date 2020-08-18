//******************************************************************************
// MainWindow.h
//	: header file for main window
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

#ifndef Ui_MainWindow_H
#define Ui_MainWindow_H

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------
#include "istream"

#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE
//class QAction;
//class QMenu;
QT_END_NAMESPACE

#ifndef Q_MOC_RUN
#include "GraphicsView.h"
#include "Config.h"
#endif // Q_MOC_RUN

//------------------------------------------------------------------------------
//	Defining Macros
//------------------------------------------------------------------------------

namespace Ui {

    //------------------------------------------------------------------------------
    //	Class definition
    //------------------------------------------------------------------------------
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    private:
    	
        Base                                        *_basePtr;
    
    private:

        Vector::GraphicsView                        *_mainGV;
	    QDockWidget                                 *_settingsDock;
	    QDockWidget                                 *_interactionDock;
        QWidget                                     *_setting;
	    QWidget                                     *_interaction;
        QMenu                                       *_viewMenu;

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        void _init  ( void );
        void _createActions     ( void );
        void _createStatusBar   ( void );
        void _createDockWindows ( void );

        void setSettings(QWidget* settingsWidget);
	    void setInteraction(QWidget* interactionWidget);

    protected:

        void mouseMoveEvent     ( QMouseEvent *event )  Q_DECL_OVERRIDE {
#ifdef DEBUG
            cerr << "#########################" << endl;
            cerr << " MainWindow::mouseMoveEvent" << endl;
            cerr << "#########################" << endl;
#endif // DEBUG
        };


    public:

        //------------------------------------------------------------------------------
        //	Constructors & Destructors
        //------------------------------------------------------------------------------
        // default constructor
        explicit MainWindow( QWidget *parent = Q_NULLPTR );
        // destructor
        ~MainWindow( void ) {}

        //------------------------------------------------------------------------------
        //	Specific functions
        //------------------------------------------------------------------------------
        void init  ( Base *__b_ptr );

	    //------------------------------------------------------------------------------
        //	I/O functions
        //------------------------------------------------------------------------------
        // output
        friend ostream &	operator << ( ostream & s, const MainWindow & m );
        // input
        friend istream &	operator >> ( istream & s, MainWindow & m );
        // class name
        virtual const char * className( void ) const { return "MainWindow"; }

    private slots:

        void newFile( void );
        void save   ( void );
        void print  ( void );
        void undo   ( void );
        void about  ( void );
        void createMainView(void);
        void _updateSetting      ( const QString &setting );
        void _updateInteraction  ( const QString &interaction );
        void _updateAllDocks    ( void );
    };

} // namespace Ui

#endif // Ui_MainWindow_H
