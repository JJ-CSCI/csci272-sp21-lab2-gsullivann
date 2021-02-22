//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

// Write your code here
class GPS {
  private:
  double latitude;
  Compass latitudeDirection;
  double longitude;
  Compass longitudeDirection;

  public:
  double getLatitude() { 
    return latitude;
  };
  Compass getLatitudeDirection() { 
    return latitudeDirection;
  };
  double getLongitude() { 
    return longitude; 
  };
  Compass getLongitudeDirection() {
     return longitudeDirection;
  };
};

GPS () {
  latitude = 0.0;
  longitude = 0.0;
  latitudeDirection = Compass::N;
  longitudeDirection = Compass::W;
}

  GPS ( latitude, longitude) {
    if (latitude >= 0.0 && latitude <= 90.0)
    latitude = latitude;
    else
    latitude = 0.0;

    if (longitude >= 0.0 && longitude <= 180.0)
    longitude = longitude;
    else
    longitude = 0.0;

    latitudeDirection = Compass::N;
    longitudeDirection = Compass::W;
  };

  GPS ( double latitude, Compass::W, double longitude, Compass latitudeDirection, Compass longitudeDirection) {
    if (latitude >= 0.0 && latitude <= 90.0){
    latitude = latitude;
    latitudeDirection = latitudeDirection;
    }

    else{
    latitude = 0.0;
    latitudeDirection = Compass::N;
    }

    if (longitude >=0.0 && longitude <= 180.0){
    longitude = longitude;
    longitudeDirection = longitudeDirection;
    }

    else{
    longitude = 0.0;
    longitudeDirection = Compass::W;
    }
  }
}


int main()
{
  GPS c;
  c.getLatitude;
  c.getLongitude;
  c.getLatitudeDirection;
  c.getLongitudeDirection;
  return 0;
}



//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
