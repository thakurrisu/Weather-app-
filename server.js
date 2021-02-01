const express = require('express')
const ejs=require('ejs')
const fun=require('./data')

const app = express();



const port = process.env.port || 3000

app.use(express.static('public'));//check this function
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
                //res.send(name);
                 temp=data.main.temp;
                 temp=temp-273;
                 temp=Math.trunc(temp);
               

                 desec=data.weather[0].description;
               
                // name=JSON.stringify(data.name);
                 //res.send({name,temp,desec});
                
                res.render('city',{x:city_name,temp:temp,desec:desec});
            }
                }
        );
    
    });

    


















    /*
    data(q,(result)=>{
            res.send('hello');
            res.send('dfaa');

  
    
     /*   const temp=JSON.parse(result).main.temp;
        console.log(temp);     
        res.end('place: '+q + 'temperature' + temp);           

           
    })
       
})*/
app.get('*', (req, res) => {
    res.status(404).send('NOT FOund')
    console.log('invalid request')
})



app.listen(port, () => {
    console.log('up and running')
})