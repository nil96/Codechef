var key="MCAF9B429I44328U";
function getUrl(companyName,SamplingRate)
{
	/*var url="https://www.quandl.com/api/v3/datasets/NSE/NFL/data.json?api_key=zQxxK9yXiyhqHMZZ7avL";
	if(SamplingRate=="Daily")
     	url="https://www.alphavantage.co/query?function=TIME_SERIES_DAILY_ADJUSTED&symbol="+ companyName +"&outputsize=full&apikey=MCAF9B429I44328U";
  else if(SamplingRate=="Weekly")
      url="https://www.alphavantage.co/query?function=TIME_SERIES_WEEKLY&symbol="+ companyName +"&apikey=MCAF9B429I44328U";
  else if(SamplingRate=="Monthly")
       url="https://www.alphavantage.co/query?function=TIME_SERIES_MONTHLY&symbol=" +  companyName +"&apikey=MCAF9B429I44328U";
  return url;*/
  var url="https://www.quandl.com/api/v3/datasets/NSE/"+companyName+"/data.json?api_key=zQxxK9yXiyhqHMZZ7avL";
  return url;
}
/*function getDataPriceToDate(data,year,samplingRate)
{

  var color1=["#00BFFF","#FF00FF","#00008B", "#008000","#FFFF00","#FFA500"," #FF0000"];
  var date=data["Meta Data"]["3. Last Refreshed"];
  var splitedDate=date.split("-");//0th index year
                                  //1st index month
                                  //2nd index day
  var rawData;
  if(samplingRate=="Daily")
    rawData = data["Time Series (Daily)"];
  else if(samplingRate="Weekly")
     rawData = data["Weekly Time Series"];
  else if(samplingRate="Monthly")
     rawData = data["Monthly Time Series"];
  var startYear=splitedDate[0]-year+1;
  var endYear=splitedDate[0];
  var formattedData=[];
  for(var i=0;i<year;i++)
  {
    formattedData[i]={};
    formattedData[i].type='scatter';
    formattedData[i].mode="lines",
    formattedData[i].line={color:color1[i] };
    formattedData[i].x={};
    formattedData[i].y={};
    formattedData[i].x=[];
    formattedData[i].y=[];
  }
  for(var itr in rawData)
  {

      var currentYear=itr.split("-")[0];
      if(currentYear<startYear)
         continue;
      else
      {
          var z=itr.split("-");
          z[0]=startYear;
          var tempDate=z[0]+"-"+ z[1] + "-" + z[2];
          formattedData[currentYear-startYear].x.push(tempDate);
          formattedData[currentYear-startYear].y.push(rawData[itr]["4. close"]); 
          formattedData[currentYear-startYear].name=currentYear;

      }
  }
  return formattedData;
}*/
function getDataPriceToDate(data,year,samplingRate)
{
   var color1=["#00BFFF","#FF00FF","#00008B", "#008000","#FFFF00","#FFA500"," #FF0000"];
   var rawData=data["dataset_data"]["data"];
   var startYear=rawData[0][0].split("-")[0]-year+1;
   var endYear=rawData[0][0].split("-")[0];
   var formattedData=[];
   for(var i=0;i<year;i++)
   {
      formattedData[i]={};
      formattedData[i].type='scatter';
      formattedData[i].mode="lines",
      formattedData[i].line={color:color1[i] };
      formattedData[i].x={};
      formattedData[i].y={};
      formattedData[i].x=[];
      formattedData[i].y=[];
   }
   for(var i=0;i<rawData.length;i++)
   {
      var temp=rawData[i];
      var date=temp[0];
      var open=temp[1];
      var high=temp[2];
      var low=temp[3];
      var last=temp[4];
      var close=temp[5];
      var totalTradeQuality=temp[6];
      var turnOver=temp[7];
      var currentYear=date.split("-")[0];
      if(currentYear<startYear)
        break;
      var z=date.split("-");
      z[0]=startYear;
      var tempDate=z[0]+"-"+ z[1] + "-" + z[2];
      formattedData[currentYear-startYear].x.push(tempDate);
      formattedData[currentYear-startYear].y.push(close); 
      formattedData[currentYear-startYear].name=currentYear;
   }
   return formattedData;
}
function PriceToDate(data,year,samplingRate)
{
    var formattedData=getDataPriceToDate(data,year,samplingRate);
    var layout = {
        xaxis: {
           type: 'date',
              },
        yaxis: {
                 title: 'Daily Mean Temperature'
               },
        margin: {
                   l: 20,
                   r: 10,
                   b: 40,
                   t: 10
                }
         title:'Stock Pricing increament'
      };

  /* var layout = {
    margin: {
    l: 20,
    r: 10,
    b: 40,
    t: 10
  },
 };*/
   // var layout = {title: 'Basic Time Series', };
    var plotData=[];
    for (var itr in formattedData)
         plotData.push(formattedData[itr]);
    Plotly.newPlot('myDiv', plotData, layout);

    
}
function PriceEarningRatio(data,year,samplingRate)
{
  var color1=["#00BFFF","#FF00FF","#00008B", "#008000","#FFFF00","#FFA500"," #FF0000"];
  var rawData=data["dataset_data"]["data"];
  var startYear=rawData[0][0].split("-")[0]-year+1;
  var endYear=rawData[0][0].split("-")[0];
  var formattedData=[];
  var monthDate[]={"01-01","02-01","03-01","04-01","05-01","06-01","07-01","08-01","09-01"",10-01","11-01","12-01"}
  for(var i=0;i<year;i++)
  {
      formattedData[i]={};
      formattedData[i].type='scatter';
      formattedData[i].mode="lines",
      formattedData[i].line={color:color1[i] };
      formattedData[i].x={};
      formattedData[i].y={};
      formattedData[i].x=[];
      formattedData[i].y=[];
  }
  var temp=rawData[i];
  var date=temp[0];
  var currentYear=date.split("-")[0];
  var startYear=currentYear-year+1;
  var Hash=[];
  while(currentYear>startYear)
  {
     var x=0;
     while(x<date.length)
     {
       date=currentYear+monthDate[x];
       Hash[date]=1;
       x=x+samplingRate;
     }
     currentYear--;
  }
  for(var i=0;i<rawData.length;i++)
   {
      temp=rawData[i];
      date=temp[0];
      if(Hash[date]!==1)
        continue;
      var open=temp[1];
      var high=temp[2];
      var low=temp[3];
      var last=temp[4];
      var close=temp[5];
      var totalTradeQuality=temp[6];
      var turnOver=temp[7];
      var currentYear=date.split("-")[0];
      var required_date=cur
      if(currentYear<startYear)
        break;
      var z=date.split("-");
      z[0]=startYear;
      var tempDate=z[0]+"-"+ z[1] + "-" + z[2];
      formattedData[currentYear-startYear].x.push(tempDate);
      formattedData[currentYear-startYear].y.push(close); 
      formattedData[currentYear-startYear].name=currentYear;
   }
   return formattedData;

}
function generateGraph(url1,year,samplingRate)
{
  $.ajax({
   url: url1,
   type: 'GET',
   success: function(data,textStatus,xhr) {
     console.log(data);
      PriceToDate(data,year,samplingRate);
   },
    error: function(xhr) {
      alert("Error occurred"+xhr.status);
   },
});

}
function getCompanyName()
{
   var CompanyName=document.getElementById("SeachBox").value;
   var url= getUrl(CompanyName,"Daily");
   generateGraph(url,5,"Daily"); 
  // alert(CompanyName);
}

