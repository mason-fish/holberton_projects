const https = require('https');
const fs = require('fs');

var options = {
    hostname: 'api.github.com',
    path: '/search/repositories?q=language:javascript&sort=stars&order=desc',
    headers: {
	'User-Agent': 'Holberton_School',
	'Authorization': 'token 1b97b1e74f551c675ad4bd92b6c327bd0fe2253d'
    }
};


var req = https.request(options, function(res) {
    streamToString(res, function(jsonString) {
	stringToObject(jsonString, function(obj) {
	    grabOwnersLocation(obj);
	    console.log("The file was written!");
	});
    });
});

req.end();

req.on('error', function(e) {
    console.error(e);
});

function stringToObject(string, cb) {
    var content = JSON.parse(string);
    var newObjectArray = [];
    for (i = 0; i < 30; i++) {
	newObjectArray[i] = {
	    full_name: content.items[i].full_name,
	    login: content.items[i].owner.login
	};
    }
    cb(newObjectArray);
}

function streamToString(stream, cb) {
    const chunks = [];
    stream.on('data', function(chunk) {
	chunks.push(chunk);
    });
    stream.on('end', function() {
	cb(chunks.join(''));
    });
}

function ownerOptions(ownerVar) {
    var optionsObject = {
	hostname: 'api.github.com',
	path: '/users/' + ownerVar,
	headers: {
	    'User-Agent': 'Holberton_School',
	    'Authorization': 'token 3b58b1fe5bc25be3b756cc32c59864d083352e0a'
	}
    }
    return optionsObject;
}

//var index = 31;
var bigObj = [];

function joinObj(stream, cb) {
//    index--;
    bigObj.push(stream);
    cb(bigObj);
/*    if (index) {
	cb(bigObj);
    }*/
}

function grabOwnersLocation(obj) {
    var chunk = obj.map(function(pass) {
	var fullObj = {};
	fullObj.full_name = pass.full_name;
	var req2 = https.request(ownerOptions(pass.login), function(res) {
	    streamToString(res, function(jsonString) {
		var content = JSON.parse(jsonString);
		fullObj.location = content.location;
		joinObj(fullObj, function(doneNow) {
		    fs.writeFile('/tmp/41', JSON.stringify(doneNow));
		});
	    });
	});
	req2.end();

	req2.on('error', function(e) {
	    console.error(e);
	});
    });
}
