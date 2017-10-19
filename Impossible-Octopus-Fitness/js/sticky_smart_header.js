var p = 0;

window.onscroll = function() {moveHeader()};

function moveHeader() {

	var h = document.querySelector("header");

	if (window.innerWidth < 550) {
		h.className = "";
		return;
	}

	var c = window.pageYOffset || document.documentElement.scrollTop;

	if (c > p + 2) {
		h.className = "sticky";
	} 

	else if (c < p - 2) {
		h.className = "";
	}
	p = c
};



