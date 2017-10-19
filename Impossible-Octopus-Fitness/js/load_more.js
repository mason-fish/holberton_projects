//javascript for load more button

window.onload = function () { //call this function onload
    javascript_enabled(event_setup);

}

function load_more(res) {
  var x = document.getElementById("loadMore");
  x.onclick = function() {
    x.disabled = true;
    x.toggle('offButton');
    window.setTimeout(function() {
      ajaxGet("/statuses-1.html", function(res) {
        document.getElementById("moreHere").innerHTML = document.getElementById("moreHere").innerHTML + res;
        event_setup(); 
      });
      x.disabled = false;
      x.toggle('offButton');
    }, 2000);
  }
}

function event_setup() {
  post_a_status();
  load_more();
  reply();
  geo_location();
  weather_button();
  template();
}

function javascript_enabled(callback){
  var postastatus = document.getElementById('post_a_status');
  document.getElementById("post_a_status").innerHTML= `
    <button type="button" id='tweetButton'><i class='fa fa-paper-plane-o'></i>Post a Status</button>
              <div id='tweetBox' class="hideTweet">
                <form  method='post'>
                  <textarea class='tweetBody' placeholder='What&quot;s on your mind?'></textarea>
                  <div class='flex'>
                    <label class='location'><input type='checkbox' name='location' value='' title='Include Location?'><span>Include Location</span></label>
                    <button id='sendButton' class='sendButton' type='button'>Post</button>
                  </div>
                </form>
              </div>

      `;

      var icons = document.querySelectorAll(".replyCode");
      for (x = 0; x < icons.length; x++) {
              icons[x].classList.add('showBox');
              icons[x].innerHTML=`
              <div class="replyBox">
                <form  method="post">
                  <textarea aria-label="yourreply" class="tweetBody" placeholder="Write your reply here"></textarea>
                  <div class="flex">
                    <label class="location">
                      <input type="checkbox" name="location" value="" title="Include Location?">Include Location</span>
                    </label>
                    <button class="sendButton" type="submit">Reply</button>
                  </div>
                </form>
              </div>
              `;

      }
      callback();
}
