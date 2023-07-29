function charValue(char) {
    // Function to return the value of a character.
    return char.charCodeAt(0) - 'a'.charCodeAt(0) + 1;
}
  
function calculateLocalCost(s) {
    // Function to calculate the local cost of a string.
    let localCost = 1;
    for (let i = 0; i < s.length; i++) {
      localCost = (localCost * charValue(s.charAt(i))) % (169 + 70);
    }
    return localCost;
}
  
function findLexicographicallySmallestMaxCostString(strings) {
    let maxLocalCost = -1;
    let maxCostStrings = [];
  
    for (let i = 0; i < strings.length; i++) {
      const s = strings[i];
      const localCost = calculateLocalCost(s);
  
      if (localCost > maxLocalCost) {
        maxLocalCost = localCost;
        maxCostStrings = [s];
      } else if (localCost === maxLocalCost) {
        maxCostStrings.push(s);
      }
    }
  
    return maxCostStrings.sort()[0];
}
  
// Example usage:
const strings = ["ab", "d", "bb", "bba", "d"];
const result = findLexicographicallySmallestMaxCostString(strings);
console.log(result);  // Output: "zzz"