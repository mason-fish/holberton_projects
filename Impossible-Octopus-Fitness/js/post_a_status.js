//Javascript for post a status, shows post a status form if user chooses to post one

function post_a_status() {
  var veil = document.getElementById('screenContent');
  document.getElementById('tweetButton').addEventListener('click', function () {
    veil.toggle('hideTweet');
  })
  document.getElementById('closeButton').addEventListener('click', function (event) {
    veil.toggle('hideTweet');
  })
}
