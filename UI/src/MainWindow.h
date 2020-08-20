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
	
	    KeiRo::Base::Base                           *_basePtr;
    
    private:

        GraphicsView                                *_mainGV;
	    QDockWidget                                 *_settingsDock;
	    QDockWidget                                 *_interactionDock;
        QWidget                                     *_setting;
	    QWidget                                     *_interaction;
        QMenu                                       *_viewMenu;

        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        template <class T> void _init  ( T *__t_ptr ){
        	
	        createMainView( __t_ptr );
	
	        _createActions();
	        _createStatusBar();
	        _createDockWindows();
	
	        setWindowTitle( tr("KeiRo") );
	        setMouseTracking( false );
	        setUnifiedTitleAndToolBarOnMac(true );
        }
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
        template <class T> void init  ( KeiRo::Base::Base *__b_ptr, T *__t_ptr ){
	        _basePtr = __b_ptr;
	        _init( __t_ptr );
        }
        
	    template <class T> void createMainView( T *__t_ptr ){
      
		    _mainGV = __t_ptr;
		    // _mainGV = new Ui::GraphicsView( this );
		    _mainGV->setStyleSheet("background: white; border: transparent;");
		    _mainGV->setGeometry( QRect( 0, 0, KeiRo::Base::Common::getDockWidgetWidth(),
		                                 KeiRo::Base::Common::getMainwidgetHeight() ) );
		    _mainGV->setMinimumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
		                                    KeiRo::Base::Common::getMainwidgetHeight() ) );
		    _mainGV->setMouseTracking( true );
		    _mainGV->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		    _mainGV->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		    _mainGV->init( _basePtr );
		    _mainGV->initSceneItems();
		
		    setCentralWidget( _mainGV );
        }

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
        void _updateSetting      ( const QString &setting );
        void _updateInteraction  ( const QString &interaction );
        void _updateAllDocks    ( void );
    };

} // namespace Ui

#endif // Ui_MainWindow_H
