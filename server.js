const express = require('express')
const ejs=require('ejs')
const fun=require('./data')

const app = express();



const port = process.env.port || 3000

app.use(express.static('public')); 
app.set('view engine','ejs');
//routes
app.get('/', (req, res) => {
  res.render('home');// console.log('Homepage')  

});

    app.get('/weather', (req, res) => {
    const city=req.query.city; //returns query string;
    if(!city)
    return res.send({
        error:"No adress found"
    });
        fun(city,(err,data)=>{
            if(err)
            res.send(err.message);
            else{
               
               city_name=data.name;
                 temp=data.main.temp;
                 temp=temp-273;
                 temp=Math.trunc(temp);
               

                 desec=data.weather[0].description;
                
                res.render('city',{x:city_name,temp:temp,desec:desec});
            }
                }
        );
    
    });






    
  
    
app.get('*', (req, res) => {
    res.status(404).send('NOT FOund')
    console.log('invalid request')
})



app.listen(port, () => {
    console.log('up and running')
})