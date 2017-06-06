var addon = require('./build/Release/accumulation.node');
module.exports = function(min, max){
	return addon.accumulation(min, max);
}
