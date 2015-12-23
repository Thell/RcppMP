#define TESTTHAT_TEST_RUNNER
#include <testthat.h>
#include <Rcpp.h>

//' Console access to c++ tests.
//'
//' @param args Single or multiple character strings.
//' @export
// [[Rcpp::export]]
bool test_cpp(Rcpp::CharacterVector args = "") {
  args.insert(args.begin(), "catch");
  auto tmp = Rcpp::as<std::vector<std::string>>(args);
  std::vector<char *> argv;
  std::transform(tmp.begin(), tmp.end(), std::back_inserter(argv),
                 [](std::string &s) { return &s[0]; });

  auto &session = testthat::catchSession();
  const auto configData = session.configData();
  int return_code = session.run((int)argv.size(), &argv[0]);
  session.useConfigData(configData);

  return return_code == 0;
}
