import React from 'react'
import PropTypes from 'prop-types'
import CourseTag from './CourseTag'
import StatBadge from './StatBadge'

function StudentCard({ name, id, avatar, gpa, major, courses }) {
  return (
    <div className="student-card" data-testid="student-card">
      <img src={avatar} alt={`${name}'s avatar`} className="student-card__avatar" />
      <div className="student-card__info">
        <h3 className="student-card__name">{name}</h3>
        <p className="student-card__id">ID: {id}</p>
        <p className="student-card__major">Major: {major}</p>
        <div className="student-card__courses">
          {courses.map((course, index) => (
            <CourseTag key={index.toString()} courseName={course} color={index % 2 === 0 ? 'blue' : 'purple'} />
          ))}
        </div>
        <div className="student-card__stats">
          <StatBadge label="GPA" value={gpa.toFixed(2)} />
          <StatBadge label="Credits" value={90 + (parseInt(id.slice(-2)) || 0) % 20} />
        </div>
      </div>
    </div>
  )
}

StudentCard.propTypes = {
  name: PropTypes.string.isRequired,
  id: PropTypes.string.isRequired,
  avatar: PropTypes.string.isRequired,
  gpa: PropTypes.number.isRequired,
  major: PropTypes.string.isRequired,
  courses: PropTypes.arrayOf(PropTypes.string).isRequired,
}
export default StudentCard
