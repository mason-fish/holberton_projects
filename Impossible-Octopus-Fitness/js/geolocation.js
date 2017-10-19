function geo_location() {
	var b = document.getElementById("sendButton");
	var buttons = document.querySelectorAll(".sendButton");
	for(var i = 0; i < buttons.length; i++) {
		var x = buttons[i];
		x.onclick = function() {
			if (this.parentElement.firstElementChild.firstElementChild.checked) {
				getLocationReply();
				showPositionReply(position);
			}
			else {
				alert("Your reply was posted!");
			}
		}
	}
	b.onclick = function(){
		if (document.getElementById("localCheck").checked) {
			getLocation();
			showPosition(position);
		} else {
			alert("Your status was posted!");
		}
	}
}

function getLocation() {
	if (navigator.geolocation) {
		navigator.geolocation.getCurrentPosition(showPosition, showError);
	} else {
		alert("Geolocation is not supported by this browser.");
	}
}

function showPosition(position) {
	alert("Your status was posted from " + position.coords.latitude + position.coords.longitude + " !");
}

function getLocationReply() {
	if (navigator.geolocation) {
		navigator.geolocation.getCurrentPosition(showPositionReply, showError);
	} else {
		alert("Geolocation is not supported by this browser.");
	}
}

function showPositionReply(position) {
	alert("Your reply was posted from " + position.coords.latitude + position.coords.longitude + " !");
}

function showError(error) {
    switch(error.code) {
        case error.PERMISSION_DENIED:
            alert("Your post went through, though without your location!");
            break;
        case error.POSITION_UNAVAILABLE:
            alert("Your post went through, though without your location!");
            break;
        case error.TIMEOUT:
            alert("Your post went through, though without your location!");
            break;
        case error.UNKNOWN_ERROR:
            alert("Your post went through, though without your location!");
            break;
    }
}
