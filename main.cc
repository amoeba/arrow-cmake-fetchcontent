#include <iostream>

#include <arrow/status.h>

arrow::Status Serve(int argc, char **argv) {
  // TODO: Write actual code here
  return arrow::Status::OK();
}

int main(int argc, char **argv) {
  arrow::Status st = Serve(argc, argv);

  if (!st.ok()) {
    std::cerr << st << std::endl;
    return 1;
  }

  return 0;
}
