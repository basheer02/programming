from pyspark.sql import SparkSession
from pyspark.sql.functions import col

# Create a Spark session
spark = SparkSession.builder \
    .appName("SimplePySparkProgram") \
    .getOrCreate()

print('hello')
# Stop the Spark session
spark.stop()
