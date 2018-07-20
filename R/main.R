#' @useDynLib Teletex
#' @importFrom Rcpp sourceCpp
NULL

#' @export
convertTeletexR = function(char){
  per_index = function(index){
    res = charToRaw(index)
    res = rawToChar(convertTeletex(res))
    Encoding(res) = 'UTF-8'
    return(res)
  }
  vapply(char, per_index, '', USE.NAMES = FALSE)
}
