import React from 'react'
import PropTypes from 'prop-types'

function CourseTag({ courseName, color }) {
  const colorClass = color ? `course-tag--${color}` : ''
  return (
    <span className={`course-tag ${colorClass}`} data-testid="course-tag">
      {courseName}
    </span>
  )
}

CourseTag.propTypes = {
  courseName: PropTypes.string.isRequired,
  color: PropTypes.oneOf(['blue', 'purple', 'orange']),
}
CourseTag.defaultProps = { color: 'blue' }
export default CourseTag
