<!DOCTYPE html>
<html>
<body>
<script>
let name = "JS";
let version = 2.7;
let releases = [2015, 2016, 2018, 2020];
let current = "2023";

console.log(name + " " + (version + 1));
document.write(releases[1] + parseInt(current));
console.log(Number.isInteger(version) ? "YES" : "NO");
releases[Math.floor(version)] = version;
document.write(releases.join("-"));
console.log(typeof releases.push(version));
let info = `${name} ${version}`;
document.write(typeof info);
console.log(Boolean(version % 2));
</script>
</body>
</html>
