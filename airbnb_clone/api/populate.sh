#!/bin/bash
### create users
curl http://localhost:3333/users -X POST -d "email=mason.e.fish@gmail.com&last_name=fish&first_name=mason&password=enternow"
curl http://localhost:3333/users -X POST -d "email=someone.else@yahoo.com&last_name=else&first_name=someone&password=sesame"
curl http://localhost:3333/users -X POST -d "email=hokay.dokey@goof.ball&last_name=bozo&first_name=clown&password=12345"

### create states
curl http://localhost:3333/states -X POST -d "name=California"
curl http://localhost:3333/states -X POST -d "name=New York"
curl http://localhost:3333/states -X POST -d "name=Colorado"

### create cities
curl http://localhost:3333/states/1/cities -X POST -d "name=Woodland"
curl http://localhost:3333/states/1/cities -X POST -d "name=San Francisco"
curl http://localhost:3333/states/1/cities -X POST -d "name=Mariposa"

curl http://localhost:3333/states/2/cities -X POST -d "name=New York City"
curl http://localhost:3333/states/2/cities -X POST -d "name=Rochester"
curl http://localhost:3333/states/2/cities -X POST -d "name=Ithaca"

curl http://localhost:3333/states/3/cities -X POST -d "name=Aspen"
curl http://localhost:3333/states/3/cities -X POST -d "name=Boulder"
curl http://localhost:3333/states/3/cities -X POST -d "name=Denver"


### create places
curl http://localhost:3333/states/1/cities/1/places -X POST -d "owner=1&name=party_house1&description=wow this place is a blast&latitude=39.45&longitude=-1.56"
curl http://localhost:3333/states/1/cities/1/places -X POST -d "owner=1&name=party_house2&description=wow this place is also a blast&latitude=40.45&longitude=-2.56"
curl http://localhost:3333/states/1/cities/1/places -X POST -d "owner=1&name=party_house3&description=wow this place is not a blast&latitude=41.45&longitude=-3.56"

curl http://localhost:3333/states/2/cities/4/places -X POST -d "owner=2&name=vacation_house1&description=wow this place is a wreck&latitude=139.45&longitude=-391.56"
curl http://localhost:3333/states/2/cities/4/places -X POST -d "owner=2&name=vacation_house2&description=wow this place is a nuthouse&latitude=239.45&longitude=-392.56"
curl http://localhost:3333/states/2/cities/5/places -X POST -d "owner=2&name=vacation_house3&description=wow this place is a cracker barrel&latitude=339.45&longitude=-393.56"

curl http://localhost:3333/states/3/cities/7/places -X POST -d "owner=3&name=boat_house1&description=wow this place is a place&latitude=3.45&longitude=-9.56"
curl http://localhost:3333/states/3/cities/9/places -X POST -d "owner=3&name=boat_house2&description=wow this place is a thing&latitude=2.45&longitude=-8.56"
curl http://localhost:3333/states/3/cities/9/places -X POST -d "owner=3&name=boat_house3&description=wow this place is a where&latitude=1.45&longitude=-7.56"

### create amenities
curl http://localhost:3333/users -X POST -d ""
curl http://localhost:3333/users -X POST -d ""
curl http://localhost:3333/users -X POST -d ""

### create place_amenities
curl http://localhost:3333/users -X POST -d ""
curl http://localhost:3333/users -X POST -d ""
curl http://localhost:3333/users -X POST -d ""

### create place_books
date_start, number_nights, user
curl http://localhost:3333/places/1/books/ -X POST -d "user=2&date_start=2016/5/28 12:30:01&number_nights=3"
curl http://localhost:3333/places/1/books/ -X POST -d "user=2&date_start=2016/6/22 12:30:01&number_nights=3"
curl http://localhost:3333/places/2/books/ -X POST -d "user=2&date_start=2016/5/28 12:30:01&number_nights=3"

### create reviews
curl http://localhost:3333/users -X POST -d ""
curl http://localhost:3333/users -X POST -d ""
curl http://localhost:3333/users -X POST -d ""

