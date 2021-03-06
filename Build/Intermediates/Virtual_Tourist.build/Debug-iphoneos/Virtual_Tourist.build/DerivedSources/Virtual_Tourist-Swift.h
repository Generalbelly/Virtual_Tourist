// Generated by Apple Swift version 2.0 (swiftlang-700.0.59 clang-700.0.72)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import CoreGraphics;
@import ObjectiveC;
@import CoreData;
@import CoreLocation;
@import MapKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class UIWindow;
@class UIApplication;
@class NSObject;

SWIFT_CLASS("_TtC15Virtual_Tourist11AppDelegate")
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow * __nullable window;
- (BOOL)application:(UIApplication * __nonnull)application didFinishLaunchingWithOptions:(NSDictionary * __nullable)launchOptions;
- (void)applicationWillResignActive:(UIApplication * __nonnull)application;
- (void)applicationDidEnterBackground:(UIApplication * __nonnull)application;
- (void)applicationWillEnterForeground:(UIApplication * __nonnull)application;
- (void)applicationDidBecomeActive:(UIApplication * __nonnull)application;
- (void)applicationWillTerminate:(UIApplication * __nonnull)application;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UIView;
@class UIActivityIndicatorView;
@class UIImageView;
@class NSCoder;

SWIFT_CLASS("_TtC15Virtual_Tourist18CollectionViewCell")
@interface CollectionViewCell : UICollectionViewCell
@property (nonatomic, weak) IBOutlet UIView * __null_unspecified view;
@property (nonatomic, weak) IBOutlet UIActivityIndicatorView * __null_unspecified activityIndicator;
@property (nonatomic, weak) IBOutlet UIImageView * __null_unspecified imageView;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURLSession;
@class Location;
@class NSError;

SWIFT_CLASS("_TtC15Virtual_Tourist12FlickrClient")
@interface FlickrClient : NSObject
+ (FlickrClient * __nonnull)sharedInstance;
@property (nonatomic) NSURLSession * __nonnull session;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)getImagesFromFlickr:(Location * __nonnull)destination completionHandler:(void (^ __nonnull)(BOOL, NSArray<NSDictionary<NSString *, NSString *> *> * __nullable, NSError * __nullable))completionHandler;
- (void)handleFlickr:(BOOL)success dics:(NSArray<NSDictionary<NSString *, NSString *> *> * __nonnull)dics destination:(Location * __nonnull)destination completionHandler:(void (^ __nonnull)(BOOL))completionHandler;
- (NSString * __nonnull)escapedParameters:(NSDictionary<NSString *, id> * __nonnull)parameters;
@end


@interface FlickrClient (SWIFT_EXTENSION(Virtual_Tourist))
@end

@class NSNumber;
@class Picture;
@class NSEntityDescription;
@class NSManagedObjectContext;
@class MKPointAnnotation;

SWIFT_CLASS("_TtC15Virtual_Tourist8Location")
@interface Location : NSManagedObject
@property (nonatomic) NSNumber * __nullable lat;
@property (nonatomic) NSNumber * __nullable lon;
@property (nonatomic, copy) NSArray<Picture *> * __nonnull pictures;
- (nonnull instancetype)initWithEntity:(NSEntityDescription * __nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * __nullable)context OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithWayPoints:(CLLocationCoordinate2D)wayPoints context:(NSManagedObjectContext * __nonnull)context OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly) MKPointAnnotation * __nonnull pin;
@end

@class NSIndexPath;
@class NSFetchedResultsController;
@class UICollectionView;
@class MKMapView;
@class UITextField;
@class UIButton;
@class NSBundle;

SWIFT_CLASS("_TtC15Virtual_Tourist24PhotoAlbumViewController")
@interface PhotoAlbumViewController : UIViewController <UIScrollViewDelegate, UICollectionViewDelegate, MKMapViewDelegate, NSFetchedResultsControllerDelegate, UICollectionViewDataSource>
@property (nonatomic, copy) NSArray<NSIndexPath *> * __null_unspecified insertedIndexPaths;
@property (nonatomic, copy) NSArray<NSIndexPath *> * __null_unspecified deletedIndexPaths;
@property (nonatomic, copy) NSArray<NSIndexPath *> * __null_unspecified updatedIndexPaths;
@property (nonatomic, copy) NSArray<NSIndexPath *> * __nonnull selectedIndexes;
@property (nonatomic) BOOL shouldUpdateBottomButton;
@property (nonatomic) Location * __null_unspecified destination;
@property (nonatomic) NSURLSession * __nullable sharedSession;
@property (nonatomic) NSFetchedResultsController * __nonnull fetchedResultsController;
@property (nonatomic, weak) IBOutlet MKMapView * __null_unspecified mapView;
@property (nonatomic, weak) IBOutlet UICollectionView * __null_unspecified collectionView;
@property (nonatomic, weak) IBOutlet UITextField * __null_unspecified noImageLabel;
@property (nonatomic, weak) IBOutlet UIButton * __null_unspecified button;
- (IBAction)backButtonTapped:(id __nonnull)sender;
- (IBAction)buttonTapped:(id __nonnull)sender;
- (void)controllerWillChangeContent:(NSFetchedResultsController * __nonnull)controller;
- (void)controller:(NSFetchedResultsController * __nonnull)controller didChangeObject:(id __nonnull)anObject atIndexPath:(NSIndexPath * __nullable)indexPath forChangeType:(NSFetchedResultsChangeType)type newIndexPath:(NSIndexPath * __nullable)newIndexPath;
- (void)controllerDidChangeContent:(NSFetchedResultsController * __nonnull)controller;
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (NSManagedObjectContext * __nonnull)sharedContext;
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView * __nonnull)collectionView;
- (void)configureCell:(CollectionViewCell * __nonnull)cell atIndexPath:(NSIndexPath * __nonnull)indexPath;
- (UICollectionViewCell * __nonnull)collectionView:(UICollectionView * __nonnull)collectionView cellForItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;
- (NSInteger)collectionView:(UICollectionView * __nonnull)collectionView numberOfItemsInSection:(NSInteger)section;
- (void)collectionView:(UICollectionView * __nonnull)collectionView didSelectItemAtIndexPath:(NSIndexPath * __nonnull)indexPath;
- (void)deleteAllPics;
- (void)deleteSelectedPics;
- (void)updateBottomButton;
- (nonnull instancetype)initWithNibName:(NSString * __nullable)nibNameOrNil bundle:(NSBundle * __nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIImage;

SWIFT_CLASS("_TtC15Virtual_Tourist7Picture")
@interface Picture : NSManagedObject
@property (nonatomic, copy) NSString * __nullable id;
@property (nonatomic, copy) NSString * __nullable imageUrlString;
@property (nonatomic) Location * __nullable destination;
- (nonnull instancetype)initWithEntity:(NSEntityDescription * __nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * __nullable)context OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithDic:(NSDictionary<NSString *, NSString *> * __nonnull)dic context:(NSManagedObjectContext * __nonnull)context OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly) UIImage * __nullable image;
@end

@class UIGestureRecognizer;
@class MKAnnotationView;
@class UIStoryboardSegue;

SWIFT_CLASS("_TtC15Virtual_Tourist31TravelLocationMapViewController")
@interface TravelLocationMapViewController : UIViewController <MKMapViewDelegate>
@property (nonatomic, weak) IBOutlet MKMapView * __null_unspecified mapView;
@property (nonatomic) Location * __nullable destination;
@property (nonatomic, copy) NSArray<Location *> * __nonnull destinations;
@property (nonatomic) BOOL noImage;
@property (nonatomic) BOOL picturesFetched;
@property (nonatomic, readonly, copy) NSString * __nonnull filePath;
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)restoreMapRegion:(BOOL)animated;
- (NSArray<Location *> * __nonnull)fetchAllDestinations;
- (void)displayAlertView:(NSString * __nonnull)message;
- (void)mapAllThePlaces:(NSArray<Location *> * __nonnull)places;
- (NSManagedObjectContext * __nonnull)sharedContext;
@property (nonatomic) NSManagedObjectContext * __nonnull temporaryContext;
- (void)enableUserPin;
- (void)action:(UIGestureRecognizer * __nonnull)gestureRecognizer;
- (void)createDragEffect:(UIGestureRecognizer * __nonnull)gestureRecognizer;
- (void)destinationSet:(UIGestureRecognizer * __nonnull)gestureRecognizer;
- (void)fetchPictures:(Location * __nonnull)destination;
- (void)mapView:(MKMapView * __nonnull)mapView didSelectAnnotationView:(MKAnnotationView * __nonnull)view;
- (void)prepareForSegue:(UIStoryboardSegue * __nonnull)segue sender:(id __nullable)sender;
- (nonnull instancetype)initWithNibName:(NSString * __nullable)nibNameOrNil bundle:(NSBundle * __nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop
