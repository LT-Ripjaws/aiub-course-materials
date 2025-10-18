<!DOCTYPE html> 
<html> 
<body> 
  <div id="container"> 
    <button id="PUSH">PUSH</button> 
    <button id="POP">POP</button> 
    <div id="status">Empty</div> 
  </div> 
  <script> 
    const status = document.getElementById("status"); 
    const PUSH = document.getElementById("PUSH"); 
    const POP = document.getElementById("POP"); 
    let stack = []; 
    let totalPushes = 0; 
 
    function updateStatus() { 
      const len = stack.length; 
      if (len === 0) { status.innerHTML = "Empty"; } 
      else if (len === 1) { status.innerHTML = "First"; } 
      else if (len % 2 === 0) { status.innerHTML = "Even"; } 
      else { status.innerHTML = "Odd"; } 
    } 
 
    function handlePush() { 
      totalPushes++; 
      stack.push(totalPushes); 
      updateStatus(); 
    } 
 
    function handlePop() { 
      if (stack.length > 0) { 
        stack.pop(); 
      } 
      updateStatus(); 
    } 
    PUSH.addEventListener("click", handlePush); 
    POP.addEventListener("click", handlePop); 
  </script> 
</body> 
</html> 