//
//  MBAppDelegate.h
//  MovieBrowse
//
//  Created by Curtis Jones on 2012.09.05.
//  Copyright (c) 2012 Curtis Jones. All rights reserved.
//

#import <Cocoa/Cocoa.h>

extern NSString * const MBDefaultsKeyImageHost;
extern NSString * const MBDefaultsKeyImageCache;
extern NSString * const MBDefaultsKeySources;
extern NSString * const MBDefaultsKeySourcesPath;
extern NSString * const MBDefaultsKeyApiTmdb;
extern NSString * const MBDefaultsKeyApiImdb;
extern NSString * const MBDefaultsKeyApiRt;

@class MBGenre;
@class MBMovie;
@class MBPerson;
@class MBDataManager;
@class MBActorMovieView;
@class MBPopUpMenu;
@class MBImportWindowController;
@class MBActorProfileWindowController;
@class MBPreferencesWindowController;
@class MBRenameWindowController;
@class MBScreencapsWindowController;

@interface MBAppDelegate : NSObject <NSApplicationDelegate, NSTableViewDelegate>

/**
 * Other
 */
@property (readonly) MBDataManager *dataManager;
@property (readonly) MBRenameWindowController *renameController;

/**
 * Main Window
 */
@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSTextField *movieInfoTxt;

/**
 * Splash Screen
 */
@property (assign) IBOutlet NSWindow *splashWin;
@property (assign) IBOutlet NSTextField *splashTxt;

/**
 * Tables
 */
@property (assign) IBOutlet NSTableView *actorTable;
@property (assign) IBOutlet NSTableView *genreTable;
@property (assign) IBOutlet NSTableView *movieTable;
@property (assign) IBOutlet NSScrollView *actorTableScrollView;
@property (assign) IBOutlet NSScrollView *genreTableScrollView;
@property (assign) IBOutlet NSScrollView *movieTableScrollView;
@property (assign) IBOutlet MBPopUpMenu *actorTableMenu;
@property (assign) IBOutlet MBPopUpMenu *genreTableMenu;
@property (assign) IBOutlet MBPopUpMenu *movieTableMenu;

/**
 * Array Controllers
 */
@property (readwrite, strong) IBOutlet NSArrayController *actorsArrayController;
@property (readwrite, strong) IBOutlet NSArrayController *genresArrayController;
@property (readwrite, strong) IBOutlet NSArrayController *moviesArrayController;

/**
 * Find
 */
@property (assign) IBOutlet NSWindow *findWindow;
@property (assign) IBOutlet NSPopUpButton *findTypeBtn;
@property (assign) IBOutlet NSTextField *findTxt;
@property (assign) IBOutlet NSButton *findBtn;
@property (assign) IBOutlet NSButton *findTitleBtn;
@property (assign) IBOutlet NSButton *findFileNameBtn;
@property (assign) IBOutlet NSButton *findDescBtn;

/**
 * Share instance.
 */
+ (MBAppDelegate *)sharedInstance;

/**
 * Used by the MBMovieView to toggle whether a movie is hidden.
 */
- (void)movie:(MBMovie *)mbmovie hideWithView:(NSView *)view;
- (void)movie:(MBMovie *)mbmovie unhideWithView:(NSView *)view;

/**
 * Display a modal sheet with the actor profile.
 */
- (void)showActor:(MBPerson *)person;

/**
 * Edit actor.
 */
- (void)editActor:(MBPerson *)person;

/**
 * Display a modal sheet with the screencaps for given movie.
 */
- (void)showScreencapsForMovie:(MBMovie *)movie;

/**
 * Edit movie details.
 */
- (void)editMovie:(MBMovie *)movie;

/**
 * Used to populate the "count" badge for each genre in the genre table.
 */
- (NSUInteger)movieCountForGenre:(MBGenre *)genre;

@end
