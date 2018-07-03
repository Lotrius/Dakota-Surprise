const button = document.getElementById("surprise");
const pic = document.getElementsByClassName("pic");

const addPic = () => {
  if(pic[0].childNodes.length < 2) {
    const img = document.createElement("img");
    img.src = "https://rlv.zcache.com/you_dont_look_an_ocelot_older_birthday_card-r33063ba37aab4f7bb091562a241c65ae_xvuat_8byvr_540.jpg";
    img.alt = "Happy birthday ocelot";
    img.height = 500;
    img.width = 500;

    pic[0].appendChild(img);
  }
}

button.addEventListener("click", addPic);
