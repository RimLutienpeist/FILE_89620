let music = document.getElementById('audio');
let musicControls = document.querySelector('.music-controls');
let musicImage = document.querySelector('.music');

function togglePlay() {
  if (music.paused) {
    music.play();
    musicImage.classList.add('rotate');
  } else {
    music.pause();
    musicImage.classList.remove('rotate');
  }
}

function changeVolume(value) {
  music.volume = value;
}

let yinyue = document.querySelector('.yinyue');
let timeoutId;

yinyue.addEventListener('mouseover', function() {
  clearTimeout(timeoutId);
  musicControls.style.opacity = '1';
});

yinyue.addEventListener('mouseout', function() {
  timeoutId = setTimeout(function() {
    musicControls.style.opacity = '0';
  }, 2000);
});

