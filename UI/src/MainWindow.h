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
#include <QtWidgets>
//#include "../../ResponsiveLens/ui/TreemapGraphicsView.h"

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
	    
        // setup timer
	    QTimer                                      *_timerptr;
	    
    private:

        GraphicsView                                *_mainGV;
	    QDockWidget                                 *_settingsDock;
	    QDockWidget                                 *_interactionDock;
        QWidget                                     *_setting;
	    GraphicsView                                *_interaction;
        QMenu                                       *_viewMenu;

        QListWidget                                 *_pathChecklist = nullptr;
        //------------------------------------------------------------------------------
        //	Special functions
        //------------------------------------------------------------------------------
        template <class T1, class T2, class T3> void _init  ( T1 *__mvPtr = NULL, T2 *__setPtr = NULL, T3 *__interactPtr = NULL ){
        	
	        _createMainView( __mvPtr );
	
	        _createActions();
	        _createStatusBar();
	        _createDockWindows( __setPtr, __interactPtr );
	
	        setWindowTitle( tr("KeiRo") );
	        setMouseTracking( false );
	        setUnifiedTitleAndToolBarOnMac(true );
        }
        void _createActions     ( void );
        void _createStatusBar   ( void );
	    template <class T> void _createMainView( T *__mvPtr ){

		    _mainGV = __mvPtr;
		    // _mainGV = new Ui::GraphicsView( this );
		    _mainGV->setStyleSheet("background: white; border: transparent;");
		    _mainGV->setGeometry( QRect( 0, 0, KeiRo::Base::Common::getDockWidgetWidth(),
		                                 KeiRo::Base::Common::getMainwidgetHeight() ) );
		    _mainGV->setMinimumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
		                                    KeiRo::Base::Common::getMainwidgetHeight() ) );
		    _mainGV->setMouseTracking( true );
//		    _mainGV->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//		    _mainGV->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		    _mainGV->init( _basePtr );
		    _mainGV->initSceneItems();
		
		    setCentralWidget( _mainGV );
	    }
	    
	    template <class T1, class T2> void _createDockWindows ( T1 *__setPtr = NULL, T2 *__interactPtr = NULL ){


	    	// setting
		    _settingsDock = new QDockWidget(tr("Setting"), this );
		    _settingsDock->setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

            // Create the tab widget
            QTabWidget *tabWidget = new QTabWidget(this);


// tab setting
            _setting = __setPtr;
//		    _setting->setGeometry( QRect(0,0,KeiRo::Base::Common::getDockWidgetWidth(),
//		                                 KeiRo::Base::Common::getMainwidgetHeight()/2.0 ) );
		    _setting->setMinimumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
		                                     KeiRo::Base::Common::getMainwidgetHeight()/2.0 ) );
//	    _setting->setMaximumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
//	                                     KeiRo::Base::Common::getMainwidgetHeight()/3.0 ) );
//        _setting->setMouseTracking( false );
		    //_settingsDock->setWidget( _setting );


// Add Setting tab
            tabWidget->addTab(_setting, tr("Setting"));

// ---------- Path Info tab ----------

            QWidget *_pathInfoWidget = new QWidget;
            QVBoxLayout *pathLayout = new QVBoxLayout(_pathInfoWidget);

            // Example labels (replace with dynamic content if needed)
            QLabel *pathLabel = new QLabel("Path information will be here: ", _pathInfoWidget);

            pathLayout->addWidget(pathLabel);
            //pathLayout->addStretch(); // Push contents to the top

            // Optional: title label
            QLabel *checklistTitle = new QLabel("Available Paths:", _pathInfoWidget);
            pathLayout->addWidget(checklistTitle);

// Create the checklist (empty for now)
            QListWidget *checklist = new QListWidget(_pathInfoWidget);
            _pathChecklist = checklist;
            _pathChecklist->setEnabled(false);
            pathLayout->addWidget(_pathChecklist);

            tabWidget->addTab(_pathInfoWidget, tr("Path Info"));

//// Fire your filter on user changes
//            connect(checklist, &QListWidget::itemChanged,
//                    this, &MainWindow::onPathFilterChanged);



            tabWidget->addTab(_pathInfoWidget, tr("Path Info"));
            // ---------- Finalize dock ----------
            _settingsDock->setWidget(tabWidget);
            addDockWidget(Qt::RightDockWidgetArea, _settingsDock);
            _viewMenu->addAction(_settingsDock->toggleViewAction());


// Create the dock and set the tab widget as its content
//            _settingsDock = new QDockWidget(tr("Settings and Info"), this);
//            _settingsDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//            _settingsDock->setWidget(tabWidget);
//            addDockWidget(Qt::RightDockWidgetArea, _settingsDock);
//            _viewMenu->addAction(_settingsDock->toggleViewAction());
//
//            addDockWidget(Qt::RightDockWidgetArea, _settingsDock );
//		    _viewMenu->addAction(_settingsDock->toggleViewAction() );


//		    // interaction
//		    _interactionDock = new QDockWidget(tr("Legend"), this );
//		    _interactionDock->setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//
//		    _interaction = __interactPtr;
//		    _interaction->setGeometry( QRect(0,0,KeiRo::Base::Common::getDockWidgetWidth(),
//		                                     KeiRo::Base::Common::getDockWidgetWidth()*KeiRo::Base::Common::getMainwidgetHeight()/KeiRo::Base::Common::getMainwidgetWidth() ) );
//		    _interaction->setMinimumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
//		                                         KeiRo::Base::Common::getDockWidgetWidth()*KeiRo::Base::Common::getMainwidgetHeight()/KeiRo::Base::Common::getMainwidgetWidth() ) );
//		    _interaction->setMaximumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
//		                                         KeiRo::Base::Common::getDockWidgetWidth()*KeiRo::Base::Common::getMainwidgetHeight()/KeiRo::Base::Common::getMainwidgetWidth() ) );
////        _interaction->setMouseTracking( false );
//            //_interaction->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//            _interaction->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//            _interaction->setFrameShape(QFrame::NoFrame);
//
//			//_interaction->init( _basePtr );
//
//		    _interactionDock->setWidget( _interaction );
//		    addDockWidget(Qt::RightDockWidgetArea, _interactionDock );
//		    _viewMenu->addAction( _interactionDock->toggleViewAction() );

// add legend widget
            _interactionDock = new QDockWidget(tr("Legend"), this);
            _interactionDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

            _interaction = __interactPtr;  // This is already a SizeTreeGraphicsView* passed in

//            _interaction->setGeometry(QRect(0, 0,
//                                            KeiRo::Base::Common::getDockWidgetWidth(),
//                                            KeiRo::Base::Common::getDockWidgetWidth() *
//                                            KeiRo::Base::Common::getMainwidgetHeight() /
//                                            KeiRo::Base::Common::getMainwidgetWidth()));

            _interaction->setMinimumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
		                                         KeiRo::Base::Common::getDockWidgetWidth()*KeiRo::Base::Common::getMainwidgetHeight()/KeiRo::Base::Common::getMainwidgetWidth() ) );
//		    _interaction->setMaximumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
//		                                         KeiRo::Base::Common::getDockWidgetWidth()*KeiRo::Base::Common::getMainwidgetHeight()/KeiRo::Base::Common::getMainwidgetWidth() ) );


            //_interaction->setStyleSheet("QGraphicsView { background-color: blue; }");
            _interaction->setBackgroundBrush(QColor(240, 240, 240));
            _interaction->setFrameShape(QFrame::NoFrame);
            _interaction->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
            _interaction->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

// Let it draw legend internally
            //_interaction->init(_basePtr);  // This calls _draw_legend() internally

            QScrollArea *scrollArea = new QScrollArea;
            scrollArea->setWidget(_interaction);  // SizeTreeGraphicsView
            scrollArea->setWidgetResizable(true);
            scrollArea->setFrameShape(QFrame::NoFrame);
            scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
            scrollArea->setMinimumSize(QSize(
                    KeiRo::Base::Common::getDockWidgetWidth(),
                    KeiRo::Base::Common::getMainwidgetHeight() * 0.25));  // Legend's initial min height


            _interactionDock->setWidget(scrollArea);
            addDockWidget(Qt::RightDockWidgetArea, _interactionDock);
            _viewMenu->addAction(_interactionDock->toggleViewAction());

            auto rebuild = [this]() {
                if (!_interaction) return;

                _interaction->init(_basePtr);              // now safe (data exists)
                auto* scene = _interaction->scene();
                if (!scene) return;

                // Scrape legend labels
                QSet<QString> labels;
                for (QGraphicsItem* gi : scene->items()) {
                    if (auto* ti = qgraphicsitem_cast<QGraphicsTextItem*>(gi)) {
                        const QString s = ti->toPlainText().trimmed();
                        if (!s.isEmpty()) labels.insert(s);
                    }
                }
                QStringList names(labels.begin(), labels.end());
                std::sort(names.begin(), names.end(),
                          [](const QString& a, const QString& b){ return a.localeAwareCompare(b) < 0; });

                _pathChecklist->blockSignals(true);
                _pathChecklist->clear();
                for (const QString& name : names) {
                    auto* it = new QListWidgetItem(name, _pathChecklist);
                    it->setFlags(it->flags() | Qt::ItemIsUserCheckable);
                    it->setCheckState(Qt::Checked);        // show all initially
                }
                _pathChecklist->blockSignals(false);
                _pathChecklist->setEnabled(!names.isEmpty());


            };
            connect(_mainGV, &GraphicsView::dataInitialized, this, [this, rebuild]{ rebuild(); });
            connect(_mainGV, &GraphicsView::dataChanged,    this, [this, rebuild]{ rebuild(); });

//	        connect( _setting, &QWidget::windowIconChanged, this, &MainWindow::_updateSetting );
//	        connect( _interaction, &QWidget::windowIconChanged, this, &MainWindow::_updateInteraction );
	    }

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
        template <class T1, class T2, class T3> void init  ( KeiRo::Base::Base *__bPtr, T1 *__mvPtr = NULL,
        		                                             T2 *__setPtr = NULL, T3 *__interactPtr = NULL ){
	        _basePtr = __bPtr;
	        _init( __mvPtr, __setPtr, __interactPtr );
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
	    void _initAllDocks      ( void );
	    void _initSetting       ( const QString &setting );
	    void _initInteraction   ( const QString &interaction );
        void _updateSetting     ( const QString &setting );
        void _updateInteraction ( const QString &interaction );
        void _updateAllDocks    ( void );

        
    public slots:
    	
	    void exportPNG( void );
	
    };

} // namespace Ui

#endif // Ui_MainWindow_H
