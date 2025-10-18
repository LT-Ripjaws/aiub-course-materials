<!doctype html> 
<html> 
    <head> 
        <style> 
            #div1 
            { 
                background-color: white; 
                display: inline; 
                position: absolute; 
                z-index: 30; 
            } 
            #div2 
            { 
                background-color: white; 
                display: inline; 
                position: absolute; 
                z-index: 20; 
            } 
            #span1 
            { 
                position: fixed; 
                right: 0; 
            } 
        </style> 
    </head> 
    <body> 
        <div id="div1">Box1</div> 
        <div id="div2">Box2</div> 
        <span id="span1">Span1</span> 
        <h1 id="h1" style="display: inline-block;">H1</h1> 
        <div id="div3" style="display: inline;">Box3</div> 
    </body> 
</html>