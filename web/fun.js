const wrapper =document.querySelector(".sliderWrapper");

const menuItem=document.querySelectorAll(".menuItems");




const products = [
  {
    id: 1,
    title: "Air Force",
    price: 119,
    colors: [
      {
        code: "black",
        img: "/img/air.png",
      },
      {
        code: "darkblue",
        img: "/img/air2.png",
      },
    ],
  },
  {
    id: 2,
    title: "Air Jordan",
    price: 149,
    colors: [
      {
        code: "lightgray",
        img: "/img/jordan.png",
      },
      {
        code: "green",
        img: "/img/jordan2.png",
      },
    ],
  },
  {
    id: 3,
    title: "Blazer",
    price: 109,
    colors: [
      {
        code: "lightgray",
        img: "/img/blazer.png",
      },
      {
        code: "green",
        img: "/img/blazer2.png",
      },
    ],
  },
  {
    id: 4,
    title: "Crater",
    price: 129,
    colors: [
      {
        code: "black",
        img: "/img/crater.png",
      },
      {
        code: "lightgray",
        img: "/img/crater2.png",
      },
    ],
  },
  {
    id: 5,
    title: "Hippie",
    price: 99,
    colors: [
      {
        code: "gray",
        img: "/img/hippie.png",
      },
      {
        code: "black",
        img: "/img/hippie2.png",
      },
    ],
  },
];



const currentProductImg=document.querySelector(".productImg");
const currentProductTitle=document.querySelector(".productTitle");
const currentProducPrice=document.querySelector(".productPrice");
const currentProducColors=document.querySelectorAll(".color");
const currentProducSizes=document.querySelectorAll(".slize");

menuItem.forEach((item,index) =>{
  item.addEventListener("click",()=>{
    
    wrapper.style.transform = `translateX(${-100 * index}vw)`;
   //change the chosen products
   chosenProducts=products[index];
 
   //change text of current products
    currentProductTitle.textContent=chosenProducts.title;
    currentProducPrice.textContent=  "$"+chosenProducts.price;
    currentProductImg.src =chosenProducts.colors[0].img;

    currentProducColors.forEach((color,index) => {
       color.style.backgroundColor=chosenProducts.colors[index].code;
    });



  
 
  });
 
});


currentProducColors.forEach((color,index)=>{
  color.addEventListener("click" ,() =>{
     currentProductImg.src= chosenProducts.colors[index].img

  });


});

const productButtonc=document.querySelector(".productButton");
const payment =document.querySelector(".payment");
const close=document.querySelector(".close");
productButtonc.addEventListener("click",()=>{
   payment.style.display="flex"

})
close.addEventListener("click",()=>{
  payment.style.display="none"

})











